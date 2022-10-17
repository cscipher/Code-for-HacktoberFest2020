const splitName = (name = '') => {
  const [firstName, ...lastName] = name.split(' ').filter(Boolean);
  return {
    firstName: firstName,
    lastName: lastName.join(' ')
  }
}
